#include <QCoreApplication>
#include <core/factories/logger-factory.h>
#include <core/factories/platform-factory.h>
#include <core/factories/test-factory.h>
#include <core/interfaces/iplatform.h>

using namespace Enum;
using namespace Factory;

int main(int argc, char *argv[]) {
	QCoreApplication application(argc, argv);
	auto platform = PlatformFactory::create(PlatformType::Linux);
	platform->attach(LoggerFactory::create(LoggerType::IniLogger));

	for (std::underlying_type<Enum::TestType>::type i = 0;
			 i < static_cast<std::underlying_type<Enum::TestType>::type>(Enum::TestType::Last); ++i)
		platform->attach(TestFactory::create(static_cast<Enum::TestType>(i)));

	platform->run();
}