#if defined _inc_env
	#undef _inc_env
#endif

#if defined _pawn_env_included
	#endinput
#endif
#define _pawn_env_included

native bool:Env_Has(const env[]);
native Env_Get(const env[], dest[], size=sizeof(dest));

#if defined _PawnPlus_included
	native Env_Get_Impl(const env[], AmxString:dest, size) = Env_Get;
	stock String:Env_Get_s(const env[])
	{
		new size = 128;
		new String:str = str_new_buf(size);

		new retSize = Env_Get_Impl(env, str, size);
		if (retSize == -1) // empty or invalid env variable
		{
			return STRING_NULL;
		}

		while (!retSize)
		{
			size *= 2;
			str_resize(str, size);
			retSize = Env_Get_Impl(env, str, size);
		}

		str_resize(str, retSize);
		return str;
	}

	#define Env_Get_Impl
#endif