/*
**EPITECH PROJECT, 2018
**CPP_babel_2021
**File description: clientconnect
**Created by Augustin Lopacinski
*/

#include <QtWidgets>
#include <iostream>
#include <QtNetwork>
#include "../include/clientconnect.hpp"
#include "../include/audio.hpp"

Client::Client(int mode, QString server_v, int port_v, QWidget *parent)
{
    in.setDevice(&tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);
    if (mode == CLIENT_CLIENT)
    	connect(&tcpSocket, &QIODevice::readyRead, this, &Client::readAudio);
    else
    	connect(&tcpSocket, &QIODevice::readyRead, this, &Client::read);
    server = server_v;
    port = port_v;
    _bytes_left = - 1;
}

void Client::setConnection(QString server_v, int port_v)
{
	server = server_v;
	port = port_v;
}

void Client::Connection()
{
	tcpSocket.abort();
	tcpSocket.connectToHost(server, port);
}

void Client::read()
{

	qint64 maxLen = 4096;
	std::pair<char *, int> line;

	while (1){
		line.first = new char[maxLen];
		line.second = tcpSocket.read(line.first, maxLen);
		if (line.second <= 0){
			std::cout << "end" << std::endl;
			return ;
		}
		else {
			std::cout << line.first << std::endl;
			std::cout << line.second << std::endl;
			std::cout << "ok" << std::endl;
		}
	}
}



void Client::readAudio()
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
                        std::cout << "size of the thing" << *((int*)line.first) << std::endl;
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

void Client::writeData(void *data, size_t size)
{
	tcpSocket.write((const char *)data, size);
}

void Client::close()
{
	tcpSocket.disconnectFromHost();
        tcpSocket.waitForDisconnected();
}

void Client::audio()
{
        paTestData          data;

        record(&data);
        std::cout << "Send" << std::endl;
        int nbr = data.maxFrameIndex * NUM_CHANNELS * sizeof(SAMPLE);
        writeData((void*)&nbr, sizeof(nbr));
        writeData((void*)data.recordedSamples, nbr);
        std::cout << "Sent" << std::endl;
}


Client::~Client()
{

}