# Assignment 1

## Title
Installation of MetaMask and study spending Ether per transaction

## Steps

1. Install the metamask extension: Go to [MetaMask.io](https://metamask.io/). Click on "Download" and select the browser you're using.

![image](https://github.com/user-attachments/assets/cb7ab6ff-8a2d-466d-9e3e-af253397377d)
![image](https://github.com/user-attachments/assets/3ed58872-57fc-44b1-913f-345b168446ef)

2. After installation, MetaMask will prompt you to either create a new wallet or import an existing one. If you're creating a new wallet, you’ll be asked to set a password. After that, you’ll get a seed phrase (12 words). Write this down and store it safely. This is the only way to recover your account if you lose access.

![Creating a wallet](https://github.com/user-attachments/assets/eda4451a-8203-46f5-92d2-b6db02ed6b8f)
![Setting a device password](https://github.com/user-attachments/assets/414e56dc-7d42-49e7-930e-2b5de87bc394)

## Transactions

When you send a transaction on the Ethereum blockchain, or interact with smart contracts, you'll spend Ether (ETH) as a fee. This fee compensates miners (in Proof of Work, or validators in Proof of Stake) for including your transaction in a block. The fee is called Gas.

### Key Concepts:
1. Gas: The unit used to measure the amount of computational effort required to execute operations on the Ethereum blockchain.

2. Gas Price: The price you're willing to pay for each unit of Gas. It’s typically measured in Gwei (1 Gwei = 0.000000001 ETH).
3. Gas Limit: The maximum amount of Gas you're willing to spend on a transaction.
Total fee = Gas used × Gas price

### Transaction Types:
1. Standard Ether Transfer: Simple transactions where you send Ether from one account to another.
2. Smart Contract Interactions: These require more computational effort, and therefore consume more gas.

### Types of Ethereum Transactions:
Legacy Transactions (before EIP-1559): You manually set the Gas price and Gas limit.
EIP-1559 Transactions: Introduced a "base fee" and a "priority fee" (tip). The base fee is burned (removed from supply), while the tip incentivizes validators.

### How to View Gas Usage in MetaMask:
1. Sending Ether:

    Click "Send" in MetaMask, enter the recipient’s address, and the amount of Ether you want to send.
    MetaMask will automatically suggest a Gas fee based on the current network conditions. You can manually adjust this.
    Interacting with Smart Contracts:
    
    If you use MetaMask with a dApp, you will also pay gas. MetaMask will display the estimated gas before confirming the transaction.
    Transaction Confirmation:
    
    After you initiate a transaction, MetaMask will show you the total Gas fee and give you an option to confirm or reject.

2. Transaction Explorer:

    You can view the status of your transaction and the exact Gas used by checking the transaction hash on Etherscan.io. MetaMask provides a link to Etherscan once the transaction is confirmed.

### Example Transaction:
Sending 0.1 ETH:

Assume the gas price is 30 Gwei and the transaction requires 21,000 gas units.
Transaction Fee = 21,000 gas × 30 Gwei = 0.00063 ETH

Interacting with a Smart Contract (e.g., swapping tokens on Uniswap):

Assume it consumes 100,000 gas and the gas price is 50 Gwei.
Transaction Fee = 100,000 gas × 50 Gwei = 0.005 ETH
