import os
from faker import Faker

fake = Faker()

NUM_FILES = 100
NUM_WORDS = 1000

def generate_random_content():
    return fake.text(max_nb_chars=NUM_WORDS)

def create_files(directory, num_files):
    try:
        if not os.path.exists(directory):
            os.makedirs(directory)
            print(f"Directory created: {directory}")
        else:
            print(f"Directory already exists: {directory}")
    except Exception as e:
        print(f"Failed to create directory {directory}: {e}")
        return

    for i in range(num_files):
        file_path = os.path.join(directory, f"{i:03}.txt")
        try:
            with open(file_path, 'w', encoding='utf-8') as file:
                file.write(generate_random_content())
            print(f"File created: {file_path}")
        except Exception as e:
            print(f"Failed to create file {file_path}: {e}")

if __name__ == "__main__":
    create_files("fileset", NUM_FILES)