require 'rubygems'
require 'socket'

TCPSocket.open("192.168.0.195", 8866) {|s|
	cmd = "#{ARGV[0]} #{ARGV[1]}#"
	puts cmd
  	s.send cmd, 0
}
