#ifndef _PARSE_COMMAND_LINE_H__
#define _PARSE_COMMAND_LINE_H__

class CommandLineInfo {
public:
    VStrList    fileNames;
    // filesToBenchmark contain 2 strings per each file to benchmark:
    // - name of the file to benchmark
    // - optional (NULL if not available) string that represents which pages
    //   to benchmark. It can also be a string "loadonly" which means we'll
    //   only benchmark loading of the catalog
    VStrList    filesToBenchmark;
    bool        makeDefault;
    bool        exitOnPrint;
    bool        printDialog;
    TCHAR *     printerName;
    int         bgColor;
    TCHAR *     inverseSearchCmdLine;
    int         fwdsearchOffset;
    int         fwdsearchWidth;
    int         fwdsearchColor;
    BOOL        fwdsearchPermanent;
    BOOL        escToExit;
    bool        reuseInstance;
    char *      lang;
    TCHAR *     destName;
    int         pageNumber;
    bool        restrictedUse;
    TCHAR *     newWindowTitle;
    BOOL        invertColors;
    bool        enterPresentation;
    HWND        hwndPluginParent;
    bool        exitImmediately;
#ifdef BUILD_RM_VERSION
    // Delete the files which were passed into the program by command line.
    bool        deleteFilesOnClose;
#endif

    CommandLineInfo() : makeDefault(false), exitOnPrint(false), printDialog(false),
        printerName(NULL), bgColor(-1), inverseSearchCmdLine(NULL),
        fwdsearchOffset(-1), fwdsearchWidth(-1), fwdsearchColor(-1),
        fwdsearchPermanent(FALSE), escToExit(FALSE),
        reuseInstance(false), lang(NULL), destName(NULL), pageNumber(-1),
        restrictedUse(false), newWindowTitle(NULL), invertColors(FALSE),
        enterPresentation(false), hwndPluginParent(NULL),
        exitImmediately(false)
#ifdef BUILD_RM_VERSION
        , deleteFilesOnClose(false)
#endif
    { }

    ~CommandLineInfo() {
        free(printerName);
        free(inverseSearchCmdLine);
        free(lang);
        free(destName);
        free(newWindowTitle);
    }

    void ParseCommandLine(TCHAR *cmdLine);

protected:
    void SetPrinterName(TCHAR *s) {
        free(printerName);
        printerName = tstr_dup(s);
    }

    void SetInverseSearchCmdLine(TCHAR *s) {
        free(inverseSearchCmdLine);
        inverseSearchCmdLine = tstr_dup(s);
    }

    void SetLang(TCHAR *s) {
        free(lang);
        lang = tstr_to_ansi(s);
    }
    
    void SetDestName(TCHAR *s) {
        free(destName);
        destName = tstr_dup(s);
    }

    void SetNewWindowTitle(TCHAR *s) {
        free(newWindowTitle);
        newWindowTitle = tstr_dup(s);
    }
};

#endif
