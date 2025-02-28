# Cloud
### VM

#### VM creation
##### TAGS
`infection`, `security`, `vulnerability`

**Situation:** An infected VM has been shutdown and now we want to investigate how a rogue software was installed and started in the VM

**Possibilities:**  
1. While installing open source softwares from the Internet, some rogue software entered the VM and got installed.
2. The VM was inside private sub-net/vectors but it was connected to a load balancer (lb)that had all inbound traffic open. Some attacker installed the rogue software connecting to the VM via the lb.

**How to investigate logs?**  
_Without starting the infected vm_
1. Create a new snapshot of the volume attached to the target vm
2. Create a _new volume_ using the snapshot
3. Attach the new volume to a new Vvm (i.e., the inspector) as a _non-root_ volume
4. Mount the volume in the inspector vm
5. Investigate the logs from the mounted volume through the inspector vm


