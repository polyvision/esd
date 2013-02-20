require 'rubygems'
require 'socket'

TCPSocket.open("localhost", 8823) {|s|
  s.send "PLAY /Users/ghostrifle/Dropbox/code/esd/tests/Applaus.wav#", 0
}
TCPSocket.open("localhost", 8823) {|s|
  s.send "PLAY /Users/ghostrifle/Dropbox/code/esd/tests/Telefon.wav#", 0
}
TCPSocket.open("localhost", 8823) {|s|
  s.send "PLAY /Users/ghostrifle/Dropbox/code/esd/tests/Applaus.wav#", 0
}
TCPSocket.open("localhost", 8823) {|s|
  s.send "PLAY /Users/ghostrifle/Dropbox/code/esd/tests/Telefon.wav#", 0
}
puts "PLAY kabuto.ogg"

