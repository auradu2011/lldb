//===-- ASTDumper.h ---------------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "clang/AST/DeclVisitor.h"
#include "clang/AST/StmtVisitor.h"
#include "clang/AST/TypeVisitor.h"

#include "lldb/Core/Stream.h"
#include "llvm/ADT/DenseSet.h"

namespace lldb_private
{
    
class ASTDumper
{
public:
    ASTDumper (clang::Decl *decl);
    ASTDumper (clang::DeclContext *decl_ctx);
    ASTDumper (clang::Type *type);
    ASTDumper (clang::QualType type);
    ASTDumper (lldb::clang_type_t type);
    
    const char *GetCString();
    void ToSTDERR();
    void ToLog(lldb::LogSP &log, const char *prefix);
    void ToStream(lldb::StreamSP &stream);
private:
    std::string m_dump;
};

} // namespace lldb_private
