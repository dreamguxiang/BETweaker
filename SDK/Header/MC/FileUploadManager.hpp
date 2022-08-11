// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Core.hpp"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class FileUploadManager {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FILEUPLOADMANAGER
public:
    class FileUploadManager& operator=(class FileUploadManager const &) = delete;
    FileUploadManager(class FileUploadManager const &) = delete;
    FileUploadManager() = delete;
#endif

public:
    /*0*/ virtual ~FileUploadManager();
    /*1*/ virtual float getUploadProgress() const;
    /*2*/ virtual void uploadFileToRealmStorage(std::string const &, class Core::Path const &, int, std::string const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_FILEUPLOADMANAGER
#endif
    MCAPI FileUploadManager(class TaskGroup &, class std::shared_ptr<class IFileChunkUploader>);
    MCAPI void addCallbackQueue(class std::function<void (void)>);
    MCAPI void setFailed(enum UploadError);
    MCAPI void setUseStream(bool);
    MCAPI void update();
    MCAPI void uploadChunk(int);
    MCAPI void uploadFile(std::string const &, class Core::Path const &, bool, class Json::Value const &);

//protected:
    MCAPI void _generateMultiPartHelper();
    MCAPI void _resumeUpload();
    MCAPI void _uploadChunk(struct FileChunkInfo const &);
    MCAPI void _uploadStream();

//private:

protected:
    MCAPI static int const CHUNK_UPLOAD_SIZE;

private:
    MCAPI static std::string const BOUNDARY;

};