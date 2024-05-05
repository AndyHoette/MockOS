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
#include "mockos/CatParsingStrategy.h"
#include "mockos/addPermissionCommand.h"

using namespace std;

int main(){
    CommandPrompt * cp = new CommandPrompt();
    AbstractFileSystem * afs = new SimpleFileSystem();
    AbstractFileFactory * aff = new SimpleFileFactory();
    cp->setFileSystem(afs);
    cp->setFileFactory(aff);
    MacroCommand * renameMacro = new MacroCommand(afs);
    AbstractParsingStrategy * renameMacroParseStrat = new RenameParsingStrategy();
    AbstractCommand * copyCommand1 = new CopyCommand(afs);
    AbstractCommand * removeCommand1 = new RemoveCommand(afs);
    renameMacro->setParseStrategy(renameMacroParseStrat);
    renameMacro->addCommand(copyCommand1);
    renameMacro->addCommand(removeCommand1);
    cp->addCommand("rn",renameMacro);
    MacroCommand * catDisplay = new MacroCommand(afs);
    AbstractParsingStrategy * catDisplayStrat = new CatParsingStrategy();
    AbstractCommand * catCommand1 = new CatCommand(afs);
    AbstractCommand * displayCommand1 = new DisplayCommand(afs);
    catDisplay->setParseStrategy(catDisplayStrat);
    catDisplay->addCommand(catCommand1);
    catDisplay->addCommand(displayCommand1);
    cp->addCommand("cds",catDisplay);
    AbstractCommand * lsCommand1 = new LSCommand(afs);
    cp->addCommand("ls",lsCommand1);
    AbstractCommand * copyCommand2 = new CopyCommand(afs);
    cp->addCommand("cp",copyCommand2);
    AbstractCommand * catCommand2 = new CatCommand(afs);
    cp->addCommand("cat",catCommand2);
    AbstractCommand * permissionCommand1 = new addPermissionCommand(afs);
    cp->addCommand("per",permissionCommand1);
    AbstractCommand * removeCommand2 = new RemoveCommand(afs);
    cp->addCommand("rm",removeCommand2);
    AbstractCommand * touchCommand1 = new TouchCommand(afs,aff);
    cp->addCommand("touch",touchCommand1);
    AbstractCommand * displayCommand2 = new DisplayCommand(afs);
    cp->addCommand("ds",displayCommand2);
    cp->run();
    cp->~CommandPrompt();
    delete cp;
    return 0;
}