require 'rubygems'
require 'socket'

TCPSocket.open("localhost", 8866) {|s|
	cmd = "#{ARGV[0]} #{ARGV[1]}#"
	puts cmd
  	s.send cmd, 0
}
