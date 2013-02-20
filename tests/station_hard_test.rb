require 'rubygems'
require 'socket'


def add_device(array,mac)
  t = Hash.new
  t['mac'] = mac
  t['state'] = false
  array << t
  return array
end
stations = Array.new

#devices
stations = add_device(stations,"666-9999")
stations = add_device(stations,"666-8888")
stations = add_device(stations,"666-7777")
stations = add_device(stations,"666-6666")
stations = add_device(stations,"666-5555")
stations = add_device(stations,"666-4444")
stations = add_device(stations,"666-3333")


num_calls = 0
randomizer = Random.new(Time.now.to_i)
for i in 0..90000 do
  current_device = stations[randomizer.rand(0..stations.size()-1)] # random station

	TCPSocket.open("localhost", 8866) {|s|
  
  if current_device['state']
  	cmd = "#{current_device['mac']} OFF#"
  	puts cmd
  	s.send cmd, 0
    current_device['state'] = false
  else
  	cmd = "#{current_device['mac']} ON#"
  	puts cmd
  	s.send cmd, 0
    current_device['state'] = true
  end
  num_calls += 1
  puts "call #{num_calls}"
  	sleep(0.5)
}
end # end of for


