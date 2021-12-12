/*
 * circular_buffer.h
 *
 *  Created on: Dec 6, 2021
 *      Author: emka
 */

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdint.h>

enum class cirBufErr_t
{
	OK,
	ERR_FULL,
	ERR_EMPTY,
	OVERRIDE
};

constexpr uint8_t DEFAULT_BUFFER_SIZE = 128;
class CircularBuffer
{
public:
	CircularBuffer(void);
	CircularBuffer(uint8_t size);
	~CircularBuffer() = default;

	cirBufErr_t put(const uint8_t item);
	cirBufErr_t take(uint8_t* const pItem);

	bool isFull(void);

private:
	uint8_t m_dataBuffer[DEFAULT_BUFFER_SIZE];
	uint8_t m_putPointer = 0;
	uint8_t m_takePointer = 0;
	const uint8_t m_bufferSize = 0;
	const uint8_t m_topPointer = 0;
	uint8_t m_dataCounter = 0;
	uint8_t getFreeSpace(void);
	void incrementPutPointer(void);
	void incrementTakePointer(void);
};



#endif /* CIRCULAR_BUFFER_H_ */
