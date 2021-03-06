#include <core/containers/compiler-info-container.h>

using namespace Container;

Enum::ContainerType CompilerInfoContainer::type() const {
	return Enum::ContainerType::CompilerInfo;
}

Core::DataStream &CompilerInfoContainer::operator<<(Core::DataStream &in) {
	in.readRawData(reinterpret_cast<char *>(&m_id), sizeof(m_id));
	in >> m_flags;
	//	m_flags << in;
	//	m_flags = in.readThrivedUtf8String();
	m_version << in;
	return in;
}

Core::DataStream &CompilerInfoContainer::operator>>(Core::DataStream &out) const {
	out.writeRawData(reinterpret_cast<const char *>(&m_id), sizeof(m_id));
	//	out.writeThrivedUtf8String(m_flags);
	out << m_flags;
	m_version >> out;
	return out;
}

Container::VersionInfoContainer &CompilerInfoContainer::version() {
	return m_version;
}

const VersionInfoContainer &CompilerInfoContainer::constVersion() const {
	return m_version;
}

Enum::CompilerType CompilerInfoContainer::id() const {
	return m_id;
}

void CompilerInfoContainer::setId(const Enum::CompilerType &id) {
	m_id = id;
}

std::string CompilerInfoContainer::checksum() const {
	return m_flags;
}

std::string CompilerInfoContainer::flags() const {
	return m_flags;
}

void CompilerInfoContainer::setFlags(const std::string &flags) {
	m_flags = flags;
}
