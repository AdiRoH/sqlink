#ifndef privateH
#define privateH

	#include "car_t_H.h"
	
	class Private_t:public car_t
	{
		public:

			inline ~Private_t();
			inline Private_t();
			inline Private_t(const Private_t& pt);
			inline const Private_t& operator=(const Private_t& pt);
			inline const unsigned int& getLineNum() const;
			inline void setLineNum(const unsigned int& lineN);
			inline const unsigned int& getSeatNum() const;
			inline void setSeatNum(const unsigned int& seatN);
			

		private:
			unsigned int m_lineNum;
			unsigned int m_seatNum;
	};



	inline Private_t::~Private_t(){}

	inline Private_t::Private_t()
	{
		m_seatNum = 52;
		m_lineNum = 26;
	}

	inline Private_t::Private_t(const Private_t& pt)
	{
		m_lineNum = pt.m_lineNum;
		m_seatNum = pt.m_seatNum;
	}

	inline const Private_t& Private_t::operator=(const Private_t& pt)
	{
		m_seatNum = pt.m_seatNum;
		m_lineNum = pt.m_lineNum;
		return *this;
	}

	inline const unsigned int& Private_t::getLineNum() const
	{
		return m_lineNum;
	}

	inline void Private_t::setLineNum(const unsigned int& lineN)
	{
		m_lineNum = lineN;
	}

	inline const unsigned int& Private_t::getSeatNum() const
	{
		return m_seatNum;
	}

	inline void Private_t::setSeatNum(const unsigned int& seatN)
	{
		m_seatNum = m_seatNum;
	}


#endif