package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"regexp"
	"strconv"
	"strings"
)

type MCRESJSON struct {
	FormatVersion int `json:"format_version"`
	Header        struct {
		Description      string `json:"description"`
		Name             string `json:"name"`
		UUID             string `json:"uuid"`
		Version          []int  `json:"version"`
		MinEngineVersion []int  `json:"min_engine_version"`
	} `json:"header"`
	Modules []struct {
		Description string `json:"description"`
		Type        string `json:"type"`
		UUID        string `json:"uuid"`
		Version     []int  `json:"version"`
	} `json:"modules"`
}

func getVersion() (int, int, int) {
	MAJOR := 0
	MINOR := 0
	REVISION := 0
	file, err := os.Open("./BETweaker/Version.h")
	if err != nil {
		log.Fatal(err)
		return MAJOR, MINOR, REVISION
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		if strings.Contains(line, "#define PLUGIN_VERSION_MAJOR") {
			out := regexp.MustCompile("[0-9]+").FindStringSubmatch(line)
			MAJOR, _ = strconv.Atoi(out[0])
		} else if strings.Contains(line, "#define PLUGIN_VERSION_MINOR") {
			out := regexp.MustCompile("[0-9]+").FindStringSubmatch(line)
			MINOR, _ = strconv.Atoi(out[0])
		} else if strings.Contains(line, "#define PLUGIN_VERSION_REVISION") {
			out := regexp.MustCompile("[0-9]+").FindStringSubmatch(line)
			REVISION, _ = strconv.Atoi(out[0])
		}
	}
	return MAJOR, MINOR, REVISION
}

func main() {
	data, err := ioutil.ReadFile("./pack/BETweaker/manifest.json")
	fmt.Println("Reading manifest.json")
	if err != nil {
		log.Fatal(err)
		return
	}
	var mcdata MCRESJSON
	if err != nil {
		return
	}
	err = json.Unmarshal(data, &mcdata)
	fmt.Println("Parsing manifest.json")
	if err != nil {
		log.Fatal(err)
	}
	a1, a2, a3 := getVersion()
	fmt.Println("Getting version :", a1, a2, a3)
	mcdata.Header.Version = []int{a1, a2, a3}
	mcdata.Modules[0].Version = []int{a1, a2, a3}
	fmt.Println("Writing manifest.json")
	data, err = json.MarshalIndent(mcdata, "", "  ")
	if err != nil {
		log.Fatal(err)
	}
	err = ioutil.WriteFile("./pack/BETweaker/manifest.json", data, 0644)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Successfully updated manifest.json")

}
