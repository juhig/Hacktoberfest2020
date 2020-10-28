"""cmd .all to tagall members of group"""
#made by @xcruzhd2


from telethon import events , TelegramClient
#goto my.telegram.org to get api_id and api_hash
api_id = 12345 #Replace 12345 with your api_id,its an interger so don't use quotes
api_hash = 'blahblah' #Replace blahblah with your api hash,its an string so use quotes
bot = TelegramClient('bohot' ,api_id, api_hash)#.start(bot_token=bot_token)

@bot.on(events.NewMessage(pattern=".all" , incoming=False,outgoing=True))
async def _(event):
    if event.fwd_from:
        return
    await event.delete()
    mentions = "@all"
    chat = await event.get_input_chat()
    async for x in bot.iter_participants(chat, None):
        mentions += f"[\u2063](tg://user?id={x.id})"
    await bot.send_message(chat, mentions, reply_to=event.message.reply_to_msg_id)


with bot:
    bot.run_until_disconnected()
