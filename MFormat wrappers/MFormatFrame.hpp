#ifndef MFORMAT_FRAME_HPP
#define MFORMAT_FRAME_HPP

//This is a partial implemntion - the minimum needed for this task

#include <atlstr.h>//CComPtr
#include "MFormats.h"//IMFFrame

namespace show_video
{
	class __declspec(dllexport) MFormatFrame
	{
	public:
		explicit MFormatFrame(CComPtr<IMFFrame> frame);
		~MFormatFrame() = default;

		int GetHeight();
		int GetWidth();
		void *GetData();
	private:
		CComPtr<IMFFrame> m_frame;
	};

}// show_video
#endif // !MFORMAT_FRAME_HPP