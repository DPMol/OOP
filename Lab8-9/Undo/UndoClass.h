#pragma once
#include <tuple>
#include <string>
#include "../Repository/repository.h"
#include "../AbstractRepo/AbstractRepo.h"
#include "../Domain/tenant.h"

class doUndo {
//    std::tuple<> arg;
//    service srv;

public:
//    template <typename... Args>
//    explicit doUndo(service& srv, Args&&... args);

    virtual void undo() = 0;
    virtual ~doUndo() = default;

};

class UndoAdd: public doUndo {
private:
    AbstractRepo& repo;
    int ap;

public:
    void undo() override;


    UndoAdd(AbstractRepo& repo, int ap);
};

class UndoDel: public doUndo {
private:
    AbstractRepo& repo;
    tenant t;

public:
    UndoDel(AbstractRepo&, tenant);
    void undo() override;
};


class UndoMod: public doUndo {
private:
    AbstractRepo& repo;
    int old_ap;
    tenant t;
public:
    UndoMod(AbstractRepo&, int, tenant);
    void undo() override;
};


