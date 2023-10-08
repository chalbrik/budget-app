#include "XmlFile.h"

string XmlFile::getFileName() const {
    return FILE_NAME;
}

void XmlFile::saveXmlFile() {
    xmlFile.Save("D:\\12_Przyszly programista\\BudgetApp\\" + FILE_NAME);
}

void XmlFile::loadXmlFile() {
    xmlFile.Load("D:\\12_Przyszly programista\\BudgetApp\\" + FILE_NAME);
}
