import json
import os
import re

class MCRESJSON:
    def __init__(self):
        self.FormatVersion = 0
        self.Header = {
            "Description": "",
            "Name": "",
            "UUID": "",
            "Version": [],
            "MinEngineVersion": []
        }
        self.Modules = [{
            "Description": "",
            "Type": "",
            "UUID": "",
            "Version": []
        }]

def getVersion():
    MAJOR = 0
    MINOR = 0
    REVISION = 0
    try:
        with open("./src/version.h", "r") as file:
            for line in file:
                if "#define PLUGIN_VERSION_MAJOR" in line:
                    out = re.findall(r'\d+', line)
                    MAJOR = int(out[0])
                elif "#define PLUGIN_VERSION_MINOR" in line:
                    out = re.findall(r'\d+', line)
                    MINOR = int(out[0])
                elif "#define PLUGIN_VERSION_REVISION" in line:
                    out = re.findall(r'\d+', line)
                    REVISION = int(out[0])
    except Exception as e:
        print(e)
    return MAJOR, MINOR, REVISION

def main():
    try:
        with open("./pack/BETweaker/manifest.json", "r") as file:
            data = file.read()
            print("Reading manifest.json")
            mcdata = json.loads(data, object_hook=lambda d: MCRESJSON())
            a1, a2, a3 = getVersion()
            print("Getting version :", a1, a2, a3)
            mcdata.Header["Version"] = [a1, a2, a3]
            mcdata.Modules[0]["Version"] = [a1, a2, a3]
            print("Writing manifest.json")
            with open("./pack/BETweaker/manifest.json", "w") as outfile:
                json.dump(mcdata.__dict__, outfile, indent=2)
            print("Successfully updated manifest.json")
    except Exception as e:
        print(e)

if __name__ == "__main__":
    main()