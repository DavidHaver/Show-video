#ifndef FRAME_GETTER_EXCEPTION_HPP
#define FRAME_GETTER_EXCEPTION_HPP

#include <exception>//std::exception

namespace show_video
{
	class FailedToGetFrame : public std::exception
	{
		//empty
	};
}// show_video
#endif // !FRAME_GETTER_EXCEPTION_HPP