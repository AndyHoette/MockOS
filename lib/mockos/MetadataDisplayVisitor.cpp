#include "mockos/MetadataDisplayVisitor.h"
#include <iostream>
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile *file) {
    cout<< file->getName() << " "
         << "text "
         << file->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile *file) {
    cout<< file->getName() << " "
        << "image "
        << file->getSize() << endl;
}