
# Wifi Module 2 Assignment 

## 1. Brief about SplitMAC architecture and how it improves the AP's performance

SplitMAC architecture is a design used in wireless networks where the functions of an access point (AP) are divided between the AP itself and a centralized Wireless LAN Controller (WLC).

#### Working:

- In a traditional AP model (Autonomous AP), all functions such as encryption, packet forwarding, authentication, and management are handled locally by the AP.
- In SplitMAC, the AP is responsible for time-sensitive functions such as:

    - Wireless frame transmission
    - Encryption/Decryption
    - MAC layer acknowledgments
    - Retransmissions

- The WLC handles higher-level functions such as:

    - Authentication and authorization
    - Roaming management
    - Quality of Service (QoS)
    - Channel and power management

#### How it Improves AP Performance:

1. ***Reduces the Processing Load on the AP:*** Since complex tasks are offloaded to the WLC, APs can focus on real-time wireless functions, reducing hardware requirements.
2. ***Enhances Scalability:*** The network can support more APs and clients without requiring each AP to perform full management functions.
3. ***Centralized Management:*** The WLC allows for unified configuration, monitoring, and troubleshooting across all APs.
4. ***Better Roaming Support:*** Clients can move seamlessly between APs without the need to reauthenticate, improving mobility.

![1.1](./images/1.1.avif)

## 2. Describe CAPWAP, explain the flow between AP and Controller

CAPWAP (Control and Provisioning of Wireless Access Points) is a tunneling protocol that enables lightweight APs to communicate with a centralized WLC over an IP network.

#### CAPWAP Flow Between AP and Controller:

1. Discovery Phase:
    - The AP finds the WLC using one of the following methods:
        - DHCP option 43
        - DNS resolution (e.g., CISCO-CAPWAP-CONTROLLER.local)
        - Static configuration

2. Join Request/Response:
    - The AP sends a CAPWAP Join Request to the WLC.
    - The WLC authenticates the AP and responds with a CAPWAP Join Response.

3. Configuration and Image Download:
    - If the AP firmware is outdated, the WLC pushes the correct firmware
    version.
    - The WLC sends configuration settings such as SSID, security policies, and
    VLAN settings to the AP.

4. Data Transfer and Management:
    - The AP begins forwarding client data through the CAPWAP tunnel.
    - Control messages continue to be exchanged for monitoring and management.

## 3. Where does CAPWAP fit in the OSI model? What are the two tunnels in CAPWAP and their purpose?

CAPWAP operates at Layer 3 (Network Layer) of the OSI model and encapsulates management and data traffic using UDP packets.

#### Two Tunnels in CAPWAP:

1. Control Tunnel (UDP port 5246):
    - Encrypts and secures communication between the AP and WLC.
    - Transmits management traffic, including authentication, configuration,
    and monitoring data.

2. Data Tunnel (UDP port 5247):
    - Transfers client data traffic between the AP and the WLC.
    - Can be configured for local switching (traffic goes directly to the LAN)
    or centralized switching (traffic is forwarded to WLC).

## 4. Difference between Lightweight APs and Cloud-based APs

| Feature              | Lightweight APs                  | Cloud-based APs                          |
|----------------------|--------------------------------|-----------------------------------------|
| **Controller**       | Requires an on-premises WLC    | Managed via a cloud-based controller   |
| **Management**       | Centralized within the local network | Remote management via a cloud dashboard |
| **Scalability**      | Limited to WLC capacity       | Highly scalable across multiple locations |
| **Cost**            | High initial investment for WLC | Lower initial cost, subscription-based pricing |
| **Deployment Complexity** | Requires network engineering expertise | Easier, as no physical controller is needed |
| **Latency**         | Dependent on WLC location      | Lower latency due to distributed cloud infrastructure |

## 5. How is the CAPWAP tunnel maintained between AP and controller?

The CAPWAP tunnel is maintained through several mechanisms:

1. Heartbeat Messages (Keepalives):
    - AP sends periodic keepalive messages to the WLC.
    - If the WLC fails to respond, the AP attempts to reconnect or switch to a
    backup controller.

2. DTLS Encryption:
    - Ensures the control and data tunnels are secure.

3. Control and Data Tunnels:
    - Control tunnel maintains WLC-to-AP communication.
    - Data tunnel transports client traffic.

4. Failover Mechanisms:
    - If the primary WLC is unreachable, APs can switch to a secondary WLC if
    configured.

## 6. Difference between Sniffer and Monitor Mode, and Use Cases

| Mode          | Description                                                      | Use Case                                              |
|--------------|------------------------------------------------------------------|------------------------------------------------------|
| **Sniffer Mode** | AP captures and forwards raw 802.11 frames to a network analyzer like Wireshark. | Troubleshooting, security audits, packet analysis.  |
| **Monitor Mode** | AP does not serve clients but scans all Wi-Fi channels to detect rogue APs and interference. | Wireless security, RF optimization, intrusion detection. |

## 7. If WLC is deployed in WAN, which AP mode is best for the local network and why?

FlexConnect Mode is the best option.

- Allows APs to continue serving clients even if the WLC connection is lost.
- Supports local authentication and switching, reducing WAN dependency.
- Provides failover mechanisms to maintain network uptime.

## 8. Challenges of Deploying More than 50 Autonomous APs in a Large Network like a University

- Configuration Overhead:
    - Each AP requires manual setup, increasing deployment time and complexity.

- Lack of Centralized Management:
    - Troubleshooting and monitoring become difficult without a centralized
    controller.
   
- Roaming Issues:
    - Clients may experience disconnections while moving between APs.

- RF Interference and Channel Management:
    - Without a WLC, APs might not properly manage their transmission power and
    channel selection, leading to signal overlap and interference.

- Security Concerns:
    - Applying consistent security policies across multiple APs is challenging.

- Scalability Issues:
    - As more APs are added, ensuring seamless connectivity and network
    performance becomes complex.

## 9. What happens when the WLC goes down while a wireless client is connected to a Lightweight AP in local mode?

If the WLC goes down:

- Existing clients remain connected but may face limited network access.
- New clients cannot connect because authentication and association require the
WLC.
- Roaming between APs may fail, causing disconnections.
- APs may reboot and try to reconnect to a backup WLC (if configured).
- Local switching may allow internal communication, but internet access might
be affected.
