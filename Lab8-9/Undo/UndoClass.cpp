#include "UndoClass.h"

#include <utility>


//template<typename... Args>
//doUndo::doUndo(service& srv, Args&&... args) :srv(srv){
//    arg = std::make_tuple( std::move(args)...);
//}

void UndoAdd::undo() {
    auto element = repo.find(ap);
    repo.del(element.value());
}

UndoAdd::UndoAdd(AbstractRepo& repo, int ap): repo(repo), ap(ap) {

}


UndoDel::UndoDel(AbstractRepo& repo, tenant t)
: repo(repo), t(t) {}

void UndoDel::undo() {
    repo.add(t);
}

UndoMod::UndoMod(AbstractRepo& repo, int old_ap, tenant t)
: repo(repo), t(t), old_ap(old_ap) {}

void UndoMod::undo() {
    auto element = repo.find(old_ap);
    repo.del(element.value());

    repo.add(t);
}
