

# ansible playbook eeror

```python
10.250.0.225 | UNREACHABLE! => {
    "changed": false, 
    "msg": "Failed to connect to the host via ssh: Permission denied (publickey,password).", 
    "unreachable": true
}
```

fix 

```bash
wangzhui@OptiPlex:/data/ansible-github/examples$ ssh-copy-id admin@10.250.0.225
/usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter out any that are already installed
/usr/bin/ssh-copy-id: INFO: 1 key(s) remain to be installed -- if you are prompted now it is to install the new keys
admin@10.250.0.225's password: 

Number of key(s) added: 1

Now try logging into the machine, with:   "ssh 'admin@10.250.0.225'"
and check to make sure that only the key(s) you wanted were added.
```

