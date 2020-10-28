import discord
from discord.ext import commands, tasks
from itertools import cycle
import asyncio
from webserver import keep_alive
import os
from discord.ext.commands import Bot
from discord.utils import get
import random

client = commands.Bot(command_prefix = 'm?')
client.remove_command ('help')

hugGifs = ['https://media.tenor.com/images/0a1652de311806ce55820a7115993853/tenor.gif', 'https://media.tenor.com/images/ce6fbe80ad07542f40b019856240db24/tenor.gif', 'https://media.tenor.com/images/8090081dc5386a5272feb8bb29747a5d/tenor.gif', 'https://media.tenor.com/images/84e96c879434a7c43437db87391b9383/tenor.gif', 'https://media.tenor.com/images/b6199ece5dca42bafad9be225e3ab1a7/tenor.gif', 'https://media.tenor.com/images/f99d706a18368646149d07cd975594e7/tenor.gif', 'https://media.tenor.com/images/52873c480047f3f8eac3d8678a312dd9/tenor.gif', 'https://media.tenor.com/images/a0a2d0be23e6162dcafc2feffba1ccc3/tenor.gif']

killGifs = ['https://media1.giphy.com/media/ZD8IgQzKCXZHefF9iQ/giphy.gif', "https://media3.giphy.com/media/SEfTzFZfaKCqZG5THN/200w.gif", "https://media1.giphy.com/media/v7XVkvDSAXq3ty0Ucm/200w.gif", "https://media4.giphy.com/media/p8w9S4V7Ivxu1va1Ym/200w.gif", "https://media2.giphy.com/media/qjsfqbLzRiJhywmxpe/200w.gif", "https://media2.giphy.com/media/G1KocC26at605fIxwU/200w.gif", "https://media3.giphy.com/media/f64OtjFzI8s0WEM27C/200w.gif", "https://media2.giphy.com/media/qjsfqbLzRiJhywmxpe/200w.gif", "https://media1.giphy.com/media/iG42fnKM3ASviDM6eS/200w.gif", "https://media4.giphy.com/media/ybnIrK28Frr6xU24tH/200w.gif", "https://media4.giphy.com/media/Th3la6tiwyXstOZ17G/200w.gif", "https://media0.giphy.com/media/1VmlZ0ZmqWf4bWr30h/200w.gif", "https://media4.giphy.com/media/Th3la6tiwyXstOZ17G/200w.gif", "https://media3.giphy.com/media/Lcsjnx7UY1bH6mId3A/200w.gif", "https://media2.giphy.com/media/cE8qdIJVMM8BcaDjcT/200w.gif", "https://media2.giphy.com/media/a78IMzNp6WmuvEikwT/200w.gif", "https://media3.giphy.com/media/bYrWBHniQ1ASSbvnZL/200w.gif", "https://media0.giphy.com/media/JURN9GTpDpvhtcEaa6/200w.gif", "https://media2.giphy.com/media/Br0myAVTcZIhYhXi8e/200w.gif", "https://media1.giphy.com/media/NI349nnxS67bLy1QG7/200w.gif", "https://media3.giphy.com/media/CenffFGkGsFfDYIulk/200w.gif", "https://media4.giphy.com/media/fbsStycUrLgIBuf3vs/200w.gif", "https://media3.giphy.com/media/2PP2hZBotxy9SquqRQ/200w.gif", "https://media1.giphy.com/media/U4d6iXC19lqW7suXEx/200w.gif", "https://media1.giphy.com/media/BvELlYgYGx0e9G2ZT2/200w.gif"]

@client.command()
async def kill(ctx, member: discord.Member):
  sender = ctx.message.author
  killem = random.choice(killGifs)
  embed = discord.Embed(
      colour=discord.Colour.green(),
      title=f'{member} was slain by {sender}',
  )
  embed.set_image(url=killem)
  embed.set_footer(text=f"Bot created by Noah")
  
  embed2 = discord.Embed(
      colour=discord.Colour.green(),
      title=f"You can't kill god, dumbass hoe.",
  )
  embed2.set_image(url='https://i.imgur.com/W5089Rh.jpg')
  embed2.set_footer(text=f"Bot created by Noah")
  
  if member.id == int(351827707031715851) or member.id == int(750810312424292499):
    await ctx.send(embed=embed2)
  else:
    await ctx.send(embed=embed)

@client.event
async def on_ready():
    print('Logged in as')
    print(client.user.name)
    print(client.user.id)
    print('------')

@client.command()
async def ping(ctx):
    await ctx.send(f'Pong! {round(client.latency * 1000)} ms')



@client.command()

async def wei(ctx):
    embed = discord.Embed(
        colour=discord.Colour.green(),
        title='Wei',
    )
    embed.set_image(url="https://lh3.googleusercontent.com/pw/ACtC-3ef9mdjAlSAxMVtO3wxdFV1_-0BZjQm3rBv_3ZkEY3bViN9PfGqBNafGrosaJl6mw0bVvfWD54ZsV8sdQnDx7v0OR9pcz6ggvCZ_sPPks4to8O1zxmID6bdDtGQ_35wGM2O0nij7LIPIYEAIEXKXYN0=w785-h191-no?authuser=0")
    embed.set_footer(text=f"Bot created by Noah")

    await ctx.send(embed=embed)

@client.command()
@commands.has_role("Bot Tester")
async def verify(ctx):
    serverIcon = str(ctx.guild.icon_url)
    pfp = str(ctx.author.avatar_url)
    creator = str(ctx.guild.name)
    imgVerify = discord.Embed(
        title=f'Hello there, and welcome to {creator}!',
        description='',
        color=discord.Color.green()
    )
    imgVerify.set_thumbnail(url=serverIcon)
    imgVerify.set_image(url="https://static.dribbble.com/users/204025/screenshots/1632701/check.gif")
    imgVerify.add_field(name = "Accept the rules and get access to all the channels by simply reacting to this message with a check mark!", value="\u200b", inline=False)
    imgVerify.set_footer(text=f"Bot created by Noah")
    await ctx.send(embed=imgVerify)



@client.command()
async def server(ctx):
    name = str(ctx.guild.name)
    description = ("Cool server.")

    owner = str(ctx.guild.owner)
    id = str(ctx.guild.id)
    region = str(ctx.guild.region)
    memberCount = str(ctx.guild.member_count)
    createdAt = str(ctx.guild.created_at)

    icon = str(ctx.guild.icon_url)

    embed = discord.Embed(
        title=name + " Server Information",
        description=description,
        color=discord.Color.green()
    )
    embed.set_thumbnail(url=icon)
    embed.add_field(name="Owner", value=owner, inline=True)
    embed.add_field(name="Region", value=region, inline=True)
    embed.add_field(name="Member Count", value=memberCount, inline=True)
    embed.add_field(name="Created At", value=createdAt, inline=True)
    embed.set_footer(text=f"Bot created by Noah")

    await ctx.send(embed=embed)

@client.command()
async def clear(ctx, amount=10):
  await ctx.channel.purge(limit=amount)


@client.command()
async def hug(ctx, member: discord.Member):
  sender = ctx.message.author
  embed = discord.Embed(
      colour=discord.Colour.green(),
      title=f'{sender} hugged {member}',
  )
  embed.set_image(url=random.choice(hugGifs))

  await ctx.send(embed=embed)

@client.command()
async def lizard(ctx):
  await ctx.send('https://www.youtube.com/watch?v=kGOQfLFzJj8')  


@client.command()
async def ivan(ctx, amount=1):
  await ctx.channel.purge(limit=amount)
  await ctx.channel.send("I want to thank you all for such a wonderful year you have given me. This was quite an experience and one crazy ride despite the short of time we all had together. Also for the teachers I just want to thank you all for not giving up on all of us, for even though we might have seemed like a pain at some point, or even though we may have not like (inaudible), or anything really, I think I and many others would want to thank you for believing in us and teaching us. you guys are amazing and I definitely won't forget this year.")

@client.command(pass_context=True)
@commands.has_role('Bot Tester')
async def nick(ctx, member: discord.Member, content, amount=1):
    nick = content
    await member.edit(nick=nick)
    await ctx.channel.purge(limit=amount)

@client.command(pass_context=True)
@commands.has_role('Donator!')
async def nicc(ctx, nick):
  member = ctx.message.author
  await member.edit(nick=str.nick)

@client.command(pass_context=True)
async def help(ctx):
    author = ctx.message.author

    test_e = discord.Embed(
        colour=discord.Colour.green()
    )
    test_e.set_author(name="Bot prefix is: m?")
    test_e.add_field(name="**Ping**", value="Pings the bot", inline=False)
    test_e.add_field(name="**Wei**", value="You wei", inline=False)
    test_e.add_field(name="**Hug**", value="hug @name", inline=False)
    test_e.add_field(name="**Lizard**", value="Motivational Lizard Video", inline=False)
    test_e.add_field(name="**Server**", value="Server information", inline=False)
    test_e.add_field(name="**Kill**", value="kill <name>")
    test_e.add_field(name="**xHamster**", value="What is an xHamster??", inline=False)
    test_e.set_footer(text=f"Bot created by Noah")

    await ctx.send(embed=test_e)

@client.command()
async def SoHanSoHot(ctx):
  await ctx.channel.send("https://cdn.discordapp.com/attachments/676858878679318564/756232524711198840/swolehan.png")

@client.command()
async def xhamster(ctx):
  await ctx.channel.send("Bruh idk LOL")

@client.command()
@commands.has_role('Bot Tester')
async def dm(ctx, member: discord.Member, *, content, amount=1):
  await ctx.channel.purge(limit=amount)
  channel = await member.create_dm() # creates a DM channel for mentioned user
  await channel.send(content) # send whatever in the content to the mentioned user.
# Usage: m!dm @mention_user <your message here>

@client.command()
@commands.has_role('Bot Tester')
async def chat(ctx, amount=1):
     await ctx.channel.purge(limit=amount)
     while True:
        test = input('')
        await ctx.send(test)


@tasks.loop(seconds=60)
async def change_status():
    await client.change_presence(activity=discord.Game("vibin' in da ritz car"))


client.run(TOKEN)
