#ifndef FORTUNESERVER_H
#define FORTUNESERVER_H

#include <QStringList>
#include <QTcpServer>
#include <QTcpSocket>

typedef std::pair<char *, int> buffer;

class ServerConnect : public QTcpServer
{
	Q_OBJECT
	
public:
	ServerConnect(quint16 port = 0, QObject *parent = 0);
	void close();
	void setConnection(int port_v);
	void Connection();
protected:
	void incomingConnection(qintptr socketDescriptor) override;
public slots:
	void readData();
	void writeData(void *data, size_t size);
	void audio();
private:
	int _port;
	int _bytes_left;
	QTcpSocket tcpSocket;
	std::vector <buffer> _buffers;
	char *_audio;
};

#endif
