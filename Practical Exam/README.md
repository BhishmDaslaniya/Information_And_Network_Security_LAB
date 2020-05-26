# Practical Exam Task INS

Refer to the attached figure (c) here. Bob is preparing to send message to Alice. Bob and Alice both secretly computes the code (s) without sharing on any communication channel. Suggest key exchange algorithm to Bob and Alice for securely exchange information without sharing actual key. Once they form secret code, Bob applies SHA256 hash algorithm on original message (M) plus code (s) and send hash of original message and code (M||s) to Alice. Alice will receive bundle of H(M||s) and first append code (s) with received message (M) and produce hash of the message (H) that compare with H(M||s) to make sure that message is not altered by any attackers.

Task to perform:
1) Use some key exchange algorithm to calculate value of s (secret code) which must be unique at sender and receiver side.
2) Implementation can be done using any programming language such as c, c++, java, python, c#, javascript, php etc.
3) Apply SHA256 on message and secret code and display it on output screen.
Verify the hash value at receiver end (Verificaton is an optional for implementation)

Note:
The evaluation criteria of task will be
a. Understandably of given definition
b. Task implementation and other unique approach
c. General understandably of related concept.

Uploading Instructions:
Upload you document in below attached google form
Save your document with your ID number
Form will accept one document at a time. Verify everyhting before final submit.