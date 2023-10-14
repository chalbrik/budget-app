#include "XmlFile.h"

string XmlFile::getFileName() const {
    return FILE_NAME;
}

void XmlFile::saveXmlFile() {
    xmlFile.Save(FILE_NAME);
}

void XmlFile::loadXmlFile() {
    xmlFile.Load(FILE_NAME);
}
