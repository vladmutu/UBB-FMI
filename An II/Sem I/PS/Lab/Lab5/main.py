import hashlib
import base64

# Function to hash the password using PBKDF2 with a given salt
def hash_password_pbkdf2(password: str, salt: bytes, iterations: int = 65536, key_length: int = 256) -> str:
    """
    Hashes a password using PBKDF2 with HMAC-SHA256.
    """
    hashed_password = hashlib.pbkdf2_hmac('sha256', password.encode(), salt, iterations, dklen=key_length // 8)
    return base64.b64encode(hashed_password).decode()

# Function to hash a password with a specific salt
def hash_password_with_salt(password: str, salt: str) -> str:
    """
    Hashes the password with a provided salt (as string).
    """
    salt_bytes = salt.encode('utf-8')  # Convert salt to bytes
    return hash_password_pbkdf2(password, salt_bytes)

# List of passwords and their corresponding salts
password_salt_pairs = [
    ("Andrei200505", "1"),
    ("123456", "2"),
    ("123456", "3"),
    ("123456", "4"),
    ("123456", "5"),
    ("Andrei200505", "6"),
    ("123456", "7")
]

# Hashing passwords with their corresponding salts
hashed_results = [(password, salt, hash_password_with_salt(password, salt)) for password, salt in password_salt_pairs]

# Print results
for password, salt, hashed in hashed_results:
    print(f"Password: {password}, Salt: {salt}, Hashed: {hashed}")
