import requests

# Substitua com os seus valores
TOKEN = "8234219492:AAHVC017yPEjHpee-1__zgfO-YaMSLtJYuY"
CHAT_ID = "6915648186"

def send_telegram_alert(message="🎈 Balão detectado!"):
    url = f"https://api.telegram.org/bot{TOKEN}/sendMessage"
    data = {"chat_id": CHAT_ID, "text": message}
    response = requests.post(url, data=data)
    if response.status_code == 200:
        print("📩 Alerta enviado com sucesso!")
    else:
        print("⚠️ Erro ao enviar alerta:", response.text)

# Teste
send_telegram_alert("🚨 Alerta de teste: o balão foi detectado!")



import time
import requests

TOKEN = "SEU_TOKEN_DO_BOT"
CHAT_ID = "SEU_CHAT_ID"
ALERT_COOLDOWN = 30  # segundos entre alertas

last_alert_time = 0  # guarda quando o último alerta foi enviado

def send_telegram_alert(message="🎈 Balão detectado!"):
    global last_alert_time
    now = time.time()
    
    if now - last_alert_time >= ALERT_COOLDOWN:
        url = f"https://api.telegram.org/bot{TOKEN}/sendMessage"
        data = {"chat_id": CHAT_ID, "text": message}
        requests.post(url, data=data)
        last_alert_time = now
        print("📩 Alerta enviado:", message)
    else:
        print("⏳ Ignorado (cooldown ativo)")