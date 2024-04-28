#pragma once
#include "AbstractFileVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"

class MetadataDisplayVisitor : public AbstractFileVisitor{
    void visit_TextFile(TextFile* file) override;
    void visit_ImageFile(ImageFile* file) override;
};
