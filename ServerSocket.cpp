#include "ServerSocket.h"
#include "SocketException.h"


ServerSocket::ServerSocket ( int port )
{
  if ( ! Socket::create() )
    {
      throw SocketException ( "Could not create server socket." );
    }

  if ( ! Socket::bind ( port ) )
    {
      throw SocketException ( "Could not bind to port." );
    }

  if ( ! Socket::listen() )
    {
      throw SocketException ( "Could not listen to socket." );
    }
}

ServerSocket::~ServerSocket()
{
}


const ServerSocket& ServerSocket::operator << ( const std::string& s ) const
{
  if ( ! Socket::send ( s ) )
    {
      throw SocketException ( "Could not write to socket." );
    }

  return *this;

}


const ServerSocket& ServerSocket::operator >> ( std::string& s ) const
{
  bool recvTest = Socket::recv (s) ;
  if ( ! recvTest )
    {
      throw SocketException ( "Could not read from socket." );
    }

  return *this;
}

bool ServerSocket::iRecv (std::string & s ) {
  return Socket::recv (s) ;
}

bool ServerSocket::accept ( ServerSocket& sock )
{
  bool sockTest = Socket::accept (sock) ;
  if ( ! sockTest )
    {
      throw SocketException ( "Could not accept socket." );
    }
  return sockTest ;
}
