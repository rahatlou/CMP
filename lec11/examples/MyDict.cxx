// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME MyDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "Datum.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *Datum_Dictionary();
   static void Datum_TClassManip(TClass*);
   static void *new_Datum(void *p = 0);
   static void *newArray_Datum(Long_t size, void *p);
   static void delete_Datum(void *p);
   static void deleteArray_Datum(void *p);
   static void destruct_Datum(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Datum*)
   {
      ::Datum *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Datum));
      static ::ROOT::TGenericClassInfo 
         instance("Datum", "Datum.h", 6,
                  typeid(::Datum), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Datum_Dictionary, isa_proxy, 0,
                  sizeof(::Datum) );
      instance.SetNew(&new_Datum);
      instance.SetNewArray(&newArray_Datum);
      instance.SetDelete(&delete_Datum);
      instance.SetDeleteArray(&deleteArray_Datum);
      instance.SetDestructor(&destruct_Datum);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Datum*)
   {
      return GenerateInitInstanceLocal((::Datum*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Datum*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Datum_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Datum*)0x0)->GetClass();
      Datum_TClassManip(theClass);
   return theClass;
   }

   static void Datum_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_Datum(void *p) {
      return  p ? new(p) ::Datum : new ::Datum;
   }
   static void *newArray_Datum(Long_t nElements, void *p) {
      return p ? new(p) ::Datum[nElements] : new ::Datum[nElements];
   }
   // Wrapper around operator delete
   static void delete_Datum(void *p) {
      delete ((::Datum*)p);
   }
   static void deleteArray_Datum(void *p) {
      delete [] ((::Datum*)p);
   }
   static void destruct_Datum(void *p) {
      typedef ::Datum current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Datum

namespace {
  void TriggerDictionaryInitialization_MyDict_Impl() {
    static const char* headers[] = {
"Datum.h",
0
    };
    static const char* includePaths[] = {
"/Users/rahatlou/Library/ROOT/v6.14.00/include",
"/Users/rahatlou/Google Drive/Didattica/Computing Methods in Physics/lec11/examples/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "MyDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$Datum.h")))  Datum;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "MyDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "Datum.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Datum", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("MyDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_MyDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_MyDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_MyDict() {
  TriggerDictionaryInitialization_MyDict_Impl();
}
