#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/PasswordProxy.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"
#include "mockos/LSCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/CopyCommand.h"
#include "mockos/MacroCommand.h"
#include "mockos/RenameParsingStrategy.h"

using namespace std;

int main(){
    CommandPrompt * cp = new CommandPrompt();
    AbstractFileSystem * afs = new SimpleFileSystem();
    AbstractFileFactory * aff = new SimpleFileFactory();
    cp->setFileSystem(afs);
    cp->setFileFactory(aff);
    MacroCommand * renameMacro = new MacroCommand();
    AbstractParsingStrategy * renameMacroParseStrat = new RenameParsingStrategy();
    AbstractCommand * copyCommand1 = new CopyCommand(afs);
    AbstractCommand * removeCommand1 = new RemoveCommand(afs, aff);
    renameMacro->setParseStrategy(renameMacroParseStrat);
    renameMacro->addCommand(copyCommand1);
    renameMacro->addCommand(removeCommand1);
    cp->addCommand("rn",renameMacro);
    return 0;
}