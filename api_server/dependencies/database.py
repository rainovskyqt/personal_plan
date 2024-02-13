from decouple import config
from playhouse.pool import PooledMySQLDatabase

dbase = PooledMySQLDatabase(None)


def init_database():
    dbase.init(
        database=config('DATABASE_NAME'),
        user=config('DATABASE_USER'),
        password=config('DATABASE_PASSWORD'),
        host=config('DATABASE_HOST'),
        port=int(config('DATABASE_PORT')),
        stale_timeout=300, # Время жизни соединения (в секундах)
        max_connections=20  # Максимальное количество соединений в пуле
    )
    dbase.connect()


def close_database():
    if not dbase.is_closed():
        dbase.close()
