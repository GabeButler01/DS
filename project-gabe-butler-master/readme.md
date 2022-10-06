# CSCI 2270 – Data Structures - Final Project 

Start by carefully reading the write-up contained in `CSCI2270_Spring22_Project.pdf`.

Please include a thorough description of your program's functionality. Imagine that you are publishing this for users who know nothing about this project. Also, include the names of the team-members/authors.

Gabe Butler

This program simulates a simple Blockchain that tracks imaginary exchnages of the cryptocurrency called Buff-CUoins.

The Blockchain will implement a list of nodes (Blocks) which each contain: nonce (necessary for mining), a vector of class Transactions, 
hash of the previous block (previousHash), timestamp (when mined), and hash of the current block.

Transactions will be marked as pending until they are mined (formally becoming a block in the blockchain).

Difficulty is a variable that will determine how difficult mining a block will be. The first n = difficulty characters of the hash must be zero to be added to the blockchain. Changing the nonce value and re-calculating the hash until this occurs is how this is done. After mining a block, the user who did it will be rewarded with Buff-CUoins.

Transactions between users are carefully monitored to ensure that no one spends Buff-CUoins that they do not have.

Validity of the blockchain is also enforced with a function that ensures that the hash of the previous block always equals previousHash of the current block throughout the entire chain.



