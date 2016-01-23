#include <core/enums/platform-type.h>

using namespace Enum;

QString Enum::name(const PlatformType &type) {
	switch (type) {
		case PlatformType::Linux:
			return "linux";
	}

	return {};
}