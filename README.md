RSA Factoring Challenge

    HTTPS uses Secure Socket Layer to encrypt data that is transferred between client and server. SSL uses the RSA algorithm, an asymmetric encryption technology. The precise details of how the algorithm works is complex, but basically it leverages the fact that whilst multiplying two large prime numbers together is easy, factoring the result back into the constituent primes is very, very hard. How all SSL/RSA encryption works is:

    The server generates two large prime numbers, and multiplies them together. This is called the "public key". This key is made available to any client which wishes to transmit data securely to the server. The client uses this "public key" to encrypt data it wishes to send. Now because this is an asymmetric algorithm, the public key cannot be used to decrypt the transmitted data, only encrypt it. In order to decrypt, you need the original prime numbers, and only the server has these (the "private key"). On receiving the encrypted data, the server uses its private key to decrypt the transmission.

    In the case of you browsing the web, your browser gives the server its public key. The server uses this key to encrypt data to be sent to your browser, which then uses its private key to decrypt.

    So yes all data transmitted to/from server over HTTPs is encrypted and encrypted well. Typical SSL implementations use 128 or 256 digits for their keys. To break this you need a truly vast amount of computing resources.

