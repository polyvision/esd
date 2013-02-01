require 'rubygems'
require 'socket'

vState = "ON"

for i in 0..100 do
	TCPSocket.open("localhost", 8866) {|s|
	cmd = "#{ARGV[0]} #{vState}#"
	puts cmd
  	s.send cmd, 0

  	if vState == "ON"
  		vState = "OFF"
  	else
  		vState = "ON"
  	end
  	sleep(1)
}
end


