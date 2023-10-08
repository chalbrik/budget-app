#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include "Markup.h"

using namespace std;

class XmlFile {

protected:

    CMarkup xmlFile;

    const string FILE_NAME;

public:

    XmlFile(string fileName) : FILE_NAME(fileName) {};

    string getFileName() const;
    void saveXmlFile();
    void loadXmlFile();

};











#endif
