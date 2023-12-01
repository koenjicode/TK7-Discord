#pragma once
#pragma once

#include <Windows.h>
#include <vector>
#include "MemoryManager.h"

namespace TekkenOverlayCommon::DataAccess {
	template<typename ObjectType>
	class ObjectProxy {
	public:
		using MultiPointerT = std::vector<uintptr_t>;
		using MultiPointerPart = uintptr_t;

		ObjectProxy() = default;

		ObjectProxy(ObjectType* ObjectPointer) {
			this->MultiPointer = { reinterpret_cast<uintptr_t>(ObjectPointer) };
		}

		template<typename... Ts>
		using AllConvertibleToMultiPointerParts = std::enable_if_t<std::conjunction_v<std::is_convertible<Ts, uintptr_t>...>>;

		template<typename... Ts, typename = AllConvertibleToMultiPointerParts<Ts...>>
		ObjectProxy(Ts const&... baseAddressAndOffsets) {
			std::vector<MultiPointerPart> pointerSequence = std::vector{ static_cast<MultiPointerPart>(baseAddressAndOffsets)... };
			for(const MultiPointerPart& offset : pointerSequence) {
				this->MultiPointer.emplace_back(offset);
			}
		}

		ObjectProxy(std::vector<uintptr_t> MultiPointer) {
			for(auto&& MultiPointerPart : MultiPointer)
				this->MultiPointer.emplace_back(MultiPointerPart);
		}

		bool IsValid() const {
			return MemoryManager::GetAddress(MultiPointer, sizeof ObjectType);
		}

		ObjectType* Get() {
			return reinterpret_cast<ObjectType*>(MemoryManager::GetAddress(this->MultiPointer, sizeof ObjectType));
		}

		operator bool() const {
			return IsValid();
		}

		ObjectType* operator->() {
			return Get();
		}

		ObjectType& operator*() {
			return *Get();
		}

		ObjectType& GetRef() {
			return *Get();
		}

		void SetValue(const ObjectType& Value) {
			GetRef() = Value;
		}

		operator ObjectType() {
			return *Get();
		}
	private:
		MultiPointerT MultiPointer{};
	};
}
