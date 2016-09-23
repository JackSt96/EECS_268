#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char* message) : std::runtime_error(message)
	{

	}
