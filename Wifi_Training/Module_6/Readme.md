
# Wi-Fi Security Assignment

## 1. What are the pillars of Wi-Fi security?

- **Authentication**: Verifying that a device or user is who they claim to be before granting access to the network.
- **Encryption**: Protecting the data being transmitted between devices and access points from being intercepted and read by unauthorized parties.
- **Integrity**: Ensuring that the data has not been tampered with during transmission.
- **Access Control**: Managing who is allowed to connect to the network and what resources they can access.

---

## 2. Explain the difference between authentication and encryption in Wi-Fi security.

- **Authentication** is the process of verifying the identity of a user or device before granting access to the network. In Wi-Fi, this typically involves proving knowledge of a shared password (pre-shared key) or using certificates or credentials (like in enterprise networks).

- **Encryption** refers to the process of scrambling the transmitted data so that even if someone intercepts the wireless traffic, they cannot understand or use the information without the correct decryption key.

---

## 3. Explain the differences between WEP, WPA, WPA2, and WPA3.

| Feature | WEP | WPA | WPA2 | WPA3 |
|:--------|:----|:----|:-----|:-----|
| Full form | Wired Equivalent Privacy | Wi-Fi Protected Access | Wi-Fi Protected Access II | Wi-Fi Protected Access III |
| Year introduced | 1997 | 2003 | 2004 | 2018 |
| Encryption | RC4 (weak) | TKIP (temporary fix) | AES-CCMP (strong) | AES-GCMP (stronger) |
| Key Management | Static | Dynamic | Dynamic | Dynamic with improved protections |
| Vulnerabilities | Easily crackable | Still vulnerable (but harder than WEP) | Secure (with strong password) | Very secure, resistant to offline attacks |
| Authentication | Shared Key | 802.1X / PSK | 802.1X / PSK | Simultaneous Authentication of Equals (SAE) |

---

## 4. Why is WEP considered insecure compared to WPA2 or WPA3?

WEP is considered insecure for several reasons:

- **Weak Encryption**: WEP uses the RC4 encryption algorithm with very short (40-bit or 104-bit) keys, which can be cracked within minutes using simple tools.
- **Static Keys**: The encryption keys in WEP are not updated dynamically. Once an attacker captures enough packets, they can derive the key.
- **Vulnerable Initialization Vectors (IVs)**: WEP uses a 24-bit IV that is reused frequently, making it easier to detect patterns and crack the key.
- **Known Exploits**: Tools like Aircrack-ng can easily crack WEP-protected networks.

In contrast, WPA2 uses dynamic key generation and a much stronger encryption algorithm (AES-CCMP), making it much harder to attack.

---

## 5. Why was WPA2 introduced?

WPA2 was introduced to address the security weaknesses found in WEP and WPA:

- **Stronger Encryption**: WPA2 mandated the use of AES encryption, which is far more secure than RC4 and TKIP.
- **Improved Integrity**: WPA2 uses CCMP (Counter Mode with Cipher Block Chaining Message Authentication Code Protocol) for both encryption and integrity checking.
- **Compliance**: WPA2 made networks compliant with stricter security requirements such as those needed by government and enterprise systems.
- **Future Proofing**: As attacks became more advanced, WPA2 provided a much more resilient foundation for wireless security.

In short, WPA2 was introduced to offer a **reliable, secure, and long-term solution** for Wi-Fi protection.

---

## 6. What is the role of the Pairwise Master Key (PMK) in the 4-way handshake?

The **Pairwise Master Key (PMK)** plays a critical role in the 4-way handshake:

- The PMK is a **pre-shared secret** derived either from the passphrase (in
WPA/WPA2-PSK) or from the authentication server (in WPA/WPA2-Enterprise).
- During the 4-way handshake, both the **client (supplicant)** and the **access
point (authenticator)** use the PMK to generate a new session key called the
**Pairwise Transient Key (PTK)**.
- The PTK is then used to encrypt and authenticate all data transmitted over the wireless network.

Thus, the PMK acts as the **base secret** from which the session keys are securely derived during authentication.

---

## 7. How does the 4-way handshake ensure mutual authentication between the client and the access point?

The 4-way handshake ensures mutual authentication as follows:

- Both the client and the access point **prove** they have the correct PMK without actually transmitting it over the air.
- **Message 1**: The AP sends a random number (ANonce) to the client.
- **Message 2**: The client responds with its own random number (SNonce) and a cryptographic value.
- **Message 3**: The AP checks the client's cryptographic value. If it matches, it means the client knows the PMK.
- **Message 4**: The client checks the AP’s cryptographic value. If it matches, it means the AP knows the PMK.

Thus, both parties confirm each other's authenticity **without exposing the shared secret**, securing the connection against impersonation.

---

## 8. What will happen if we put a wrong passphrase during a 4-way handshake?

If a wrong passphrase is entered:

- The derived **PMK** on the client side will not match the PMK on the access point.
- As a result, during the 4-way handshake, the **Message Integrity Code (MIC)** calculated by the client and the AP will not match.
- The access point will detect this mismatch and **abort the handshake**, refusing to allow the client to join the network.

**Outcome**: The client will **fail to authenticate** and will not gain network access.

---

## 9. What problem does 802.1X solve in a network?

**802.1X** solves the problem of:

- **Controlling network access** based on user authentication.
- **Separating authentication from encryption** in network access.
- **Dynamic key distribution**, reducing the risk of key compromise.
- Providing **identity-based access control**, ensuring that only authorized users and devices can access the network.

It is especially important in large networks (like enterprises, universities, etc.) where managing shared passwords (like in WPA-PSK) would be insecure and impractical.

---

## 10. How does 802.1X enhance security over wireless networks?

802.1X enhances wireless security by:

- **Using unique credentials** (such as usernames, certificates, or smart cards) instead of shared passwords.
- **Authenticating each user/device individually** through an authentication server (like RADIUS).
- **Enabling dynamic encryption keys** for each session, which reduces the chance of session hijacking.
- **Supporting stronger authentication methods** (e.g., EAP-TLS) that use certificates for robust security.
- **Preventing rogue devices** from easily connecting to the network, reducing risk of attacks like Man-in-the-Middle (MitM) and rogue APs.

Thus, 802.1X provides **enterprise-grade security** for Wi-Fi networks.

---
