import sys
import requests
import os

def main(fileName):
    try:
        path = os.path.dirname(
            os.path.realpath(__file__)) + "\\" + fileName
        f = open(path,
                 mode='rt')
        urlList = f.readlines()
        for u in urlList:
            response = requests.get(u.strip())
            try:
                response.raise_for_status()
                ofname = u.split('/')[-1].strip()
                opath = os.path.dirname(
                    os.path.realpath(__file__)) + "\\" + ofname
                pdf = open(opath, 'wb')
                sz = pdf.write(response.content)
                print('Downloading', ofname, '...')
                print("Written", sz, "bytes")
                pdf.close()
            except Exception as ex:
                print(f'There was a problem: {ex} while downloading {u}!')
        f.close()
    except Exception as e:
        print('[ERROR]', e) 
    
# print(os.path.dirname(os.path.realpath(__file__)))
# print(os.getcwd())

if __name__ == '__main__':
    main(sys.argv[1])
