#pragma once
#include <tuple>
#include <string>
#include "repository.h"
#include "tenant.h"

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
    Repository& repo;
    int ap;

public:
    void undo() override;


    UndoAdd(Repository& repo, int ap);
};

class UndoDel: public doUndo {
private:
    Repository& repo;
    tenant t;

public:
    UndoDel(Repository&, tenant);
    void undo() override;
};


class UndoMod: public doUndo {
private:
    Repository& repo;
    int old_ap;
    tenant t;
public:
    UndoMod(Repository&, int, tenant);
    void undo() override;
};


