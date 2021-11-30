# CNProject
IPv4 Addressing and DHCP
This tool takes an IPv4 Address and a Network Mask as inputs. It validates the IP Address and with the help of the mask, determines the Network Address for the given inputs. The tool also calculates the block size of the given subnet and generates random network addresses with the same block size. For the randomly generated network addresses, the tool creates a random IP pool of addresses within the network and stores it as a database. 
Additionally, a DHCP-like client, receives a random IP from a DHCP-like server that responds with a chosen IP address stored in its network database pool
