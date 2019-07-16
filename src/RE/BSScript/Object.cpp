#include "RE/BSScript/Object.h"

#include "RE/BSScript/Internal/VirtualMachine.h"  // BSScript::Internal::VirtualMachine
#include "RE/BSScript/IObjectHandlePolicy.h"  // BSScript::IObjectHandlePolicy
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace BSScript
	{
		Class* Object::GetClass()
		{
			return classPtr.get();
		}


		const Class* Object::GetClass() const
		{
			return classPtr.get();
		}


		void* Object::Resolve(UInt32 a_typeID) const
		{
			auto policy = Internal::VirtualMachine::GetSingleton()->GetHandlePolicyBS();
			if (policy->IsType(a_typeID, handle) && policy->IsValidHandle(handle)) {
				return policy->Resolve(a_typeID, handle);
			} else {
				return 0;
			}
		}


		void Object::IncRefCount()
		{
			using func_t = function_type_t<decltype(&Object::IncRefCount)>;
			REL::Offset<func_t*> func(Offset::BSScript::BSScriptObject::IncRefCount);
			return func(this);
		}


		SInt32 Object::DecRefCount()
		{
			using func_t = function_type_t<decltype(&Object::DecRefCount)>;
			REL::Offset<func_t*> func(Offset::BSScript::BSScriptObject::DecRefCount);
			return func(this);
		}
	}
}