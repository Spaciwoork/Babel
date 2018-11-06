#include <QtNetwork>
#include <iostream>
#include <QRandomGenerator>
#include <stdlib.h>
#include "../include/serverconnect.hpp"
#include "../include/audio.hpp"

ServerConnect::ServerConnect(quint16 port, QObject *parent)
    : QTcpServer(parent)
{
	_port = port;
	_bytes_left = -1;
}

void ServerConnect::setConnection(int port_v)
{
	_port = port_v;
	close();
	Connection();
}

void ServerConnect::Connection()
{
	listen(QHostAddress::Any, _port);
}

void ServerConnect::incomingConnection(qintptr socketDescriptor)
{
    connect(&tcpSocket, &QIODevice::channelReadyRead, this, &ServerConnect::readData);
    if (!tcpSocket.setSocketDescriptor(socketDescriptor)) {
        return;
    }

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);

    //audio();
}

void ServerConnect::close()
{
	tcpSocket.disconnectFromHost();
	tcpSocket.waitForDisconnected();
}
void ServerConnect::readData()
{
	std::cout << "Incoming" << std::endl;
	qint64 maxLen = 705600;
        std::pair<char *, int> line;

        while (1){
                line.first = new char[maxLen];
                line.second = tcpSocket.read(line.first, maxLen);
		if (line.second <= 0){
                        return ;
		}
		if (_bytes_left == -1){
			std::cout << *((int*)line.first) << std::endl;
			_bytes_left = *((int*)line.first);
			_audio = new char[_bytes_left];
		}
		else if (_bytes_left > 0){
			_buffers.push_back(line);
			_bytes_left -= line.second;
			std::cout << "Size left---->" << _bytes_left << std::endl;
		}
		int bytes = 0;
		if (_bytes_left == 0){
			std::cout << _buffers.size() << std::endl;
			for (auto it = _buffers.begin(); it!=_buffers.end(); ++it){
				memcpy(&_audio[bytes], it->first, it->second);
				std::cout << "+" << it->second << std::endl;
				bytes += it->second;
			}
			std::cout << bytes << std::endl;
			paTestData data;
                        data.recordedSamples = (SAMPLE *)_audio;
			std::cout << "+" << bytes << std::endl;
                        play_sound(data, (bytes / (sizeof(SAMPLE) * NUM_CHANNELS)));
			delete data.recordedSamples;
			_buffers.clear();
			_bytes_left = -1;
		}
        }
}

void ServerConnect::writeData(void *data, size_t size)
{
	tcpSocket.write((const char *)data, size);
}

void ServerConnect::audio()
{
        paTestData          data;

        record(&data);
        std::cout << "Send" << std::endl;
        int nbr = data.maxFrameIndex * NUM_CHANNELS * sizeof(SAMPLE);
        writeData((void*)&nbr, sizeof(nbr));
        writeData((void*)data.recordedSamples, nbr);
        std::cout << "Sent" << std::endl;
}
