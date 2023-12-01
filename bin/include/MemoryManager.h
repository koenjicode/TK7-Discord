#pragma once

#include <vector>
#include <Windows.h>

namespace TekkenOverlayCommon::DataAccess {
	class MemoryManager {
	public:
		static uintptr_t GetAddress(std::vector<uintptr_t> multiPointer, std::size_t typeSize) {
			if(multiPointer.empty())
				return 0;

			if(multiPointer.size() == 1) {
				if(IsBadReadPtr(reinterpret_cast<void*>(multiPointer.front()), typeSize))
					return 0;
				return multiPointer.front();
			}
			if(multiPointer.size() == 2) {
				if(IsBadReadPtr(reinterpret_cast<void*>(multiPointer.front() + multiPointer.back()), typeSize))
					return 0;
				return multiPointer.front() + multiPointer.back();
			}

			else {
				uintptr_t baseAddress = multiPointer[0];
				uintptr_t address;

				for(size_t currentOffsetIndex = 1; currentOffsetIndex < multiPointer.size() - 1; ++currentOffsetIndex) {
					uintptr_t currentOffset = multiPointer[currentOffsetIndex];
					address = baseAddress + currentOffset;

					if(IsBadReadPtr(reinterpret_cast<void*>(address), sizeof(uintptr_t)))
						return 0;

					// else if pointer is good, dereference it, save as base address and continue
					baseAddress = *reinterpret_cast<uintptr_t*>(address);
				}

				// After dereferencing all offsets except last one, add the last offset
				address = baseAddress + multiPointer.back();

				// If the end address is bad, return 0
				if(IsBadReadPtr(reinterpret_cast<void*>(address), typeSize))
					return 0;

				return address;
			}
		}
	};
}
