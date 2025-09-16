#ifndef MFORMAT_READER_HPP
#define MFORMAT_READER_HPP

//This is a partial implemntion - the minimum needed for this task

#include <string>//std::string
#include "MFormatFrame.hpp"//MFormatFrame , CComPtr, IMFReader

namespace show_video
{

	class __declspec(dllexport) MFormatReader
	{
	public:
		explicit MFormatReader(const std::string &filePath);
		MFormatReader(const MFormatReader &other) = delete;
		MFormatReader(MFormatReader &&other) = delete;
		~MFormatReader() noexcept;
		MFormatReader &operator=(const MFormatReader &rhs) = delete;
		MFormatReader& operator=(MFormatReader &&rhs) = delete;

		//throw FailedToGetFrame when could not get frame 
		MFormatFrame GetNextFrame();

	private:
		CComPtr<IMFReader> m_reader;
		bool m_rewind;
	};

}// show_video
#endif // !MFORMAT_READER_HPP
