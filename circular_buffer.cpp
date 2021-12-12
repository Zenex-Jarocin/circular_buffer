/*
 * eMKa elektronika
 */

#include "circular_buffer.h"

CircularBuffer::CircularBuffer()
:
m_bufferSize(DEFAULT_BUFFER_SIZE),
m_topPointer(DEFAULT_BUFFER_SIZE - 1)
{
}

CircularBuffer::CircularBuffer(uint8_t size)
:
m_bufferSize(size),
m_topPointer(size - 1)
{
}

cirBufErr_t CircularBuffer::put(const uint8_t item)
{
	if ((m_bufferSize - m_dataCounter) == 0)
		return cirBufErr_t::ERR_FULL;

	m_dataBuffer[m_putPointer] = item;
	incrementPutPointer();
	m_dataCounter++;
	return cirBufErr_t::OK;

}
cirBufErr_t CircularBuffer::take(uint8_t* const pItem)
{
	if (m_dataCounter == 0)
		return cirBufErr_t::ERR_EMPTY;

	*pItem = m_dataBuffer[m_takePointer];
	m_dataCounter--;
	incrementTakePointer();
	return cirBufErr_t::OK;
}

bool CircularBuffer::isFull(void)
{
	return (this->getFreeSpace() == 0);
}


uint8_t CircularBuffer::getFreeSpace(void)
{
	if (m_putPointer == m_takePointer)
		return m_bufferSize - m_dataCounter;

	if (m_putPointer > m_takePointer)
		return m_bufferSize - (m_putPointer - m_takePointer);

	if (m_putPointer < m_takePointer)
		return m_takePointer - m_putPointer;

	return 0;
}

void CircularBuffer::incrementPutPointer(void)
{
	if (m_putPointer == m_topPointer)
	{
		m_putPointer = 0;
		return;
	}

	m_putPointer++;
}

void CircularBuffer::incrementTakePointer(void)
{
	if (m_takePointer== m_topPointer)
	{
		m_takePointer = 0;
		return;
	}

	m_takePointer++;
}
